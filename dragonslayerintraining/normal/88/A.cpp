#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main(){
  std::map<std::string,int> notemap;
  notemap["C"]=0;
  notemap["C#"]=1;
  notemap["D"]=2;
  notemap["D#"]=3;
  notemap["E"]=4;
  notemap["F"]=5;
  notemap["F#"]=6;
  notemap["G"]=7;
  notemap["G#"]=8;
  notemap["A"]=9;
  notemap["B"]=10;
  notemap["H"]=11;
  int notes[3];
  int min=12;
  for(int i=0;i<3;i++){
    std::string name;
    std::cin>>name;
    notes[i]=notemap[name];
    min=std::min(min,notes[i]);
  }
  for(int i=0;i<3;i++){
    notes[i]-=min;
  }
  std::sort(notes,notes+3);
  if(((notes[1]==4)&&(notes[2]==7))||
     ((notes[1]==3)&&(notes[2]==8))||
     ((notes[1]==5)&&(notes[2]==9))){
    std::cout<<"major"<<std::endl;
  }else if(((notes[1]==3)&&(notes[2]==7))||
	   ((notes[1]==4)&&(notes[2]==9))||
	   ((notes[1]==5)&&(notes[2]==8))){
    std::cout<<"minor"<<std::endl;
  }else{
    std::cout<<"strange"<<std::endl;
  }
  return 0;
}