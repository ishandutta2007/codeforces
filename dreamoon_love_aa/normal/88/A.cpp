#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string,int>H;
int f(int x){
    if(x<0)x+=12;
    return x;
}
int d[3];
main(){
    H["C"]=0;
    H["C#"]=1;
    H["D"]=2;
    H["D#"]=3;
    H["E"]=4;
    H["F"]=5;
    H["F#"]=6;
    H["G"]=7;
    H["G#"]=8;
    H["A"]=9;
    H["B"]=10;
    H["H"]=11;
    char s[3][8];
    int i;
    for(i=0;i<3;i++)scanf("%s",s[i]),d[i]=H[s[i]];
    sort(d,d+3);
    if(f(d[1]-d[0])==4&&f(d[2]-d[1])==3
     ||f(d[2]-d[1])==4&&f(d[0]-d[2])==3
     ||f(d[0]-d[2])==4&&f(d[1]-d[0])==3)puts("major");
    else if(f(d[1]-d[0])==3&&f(d[2]-d[1])==4
     ||f(d[2]-d[1])==3&&f(d[0]-d[2])==4
     ||f(d[0]-d[2])==3&&f(d[1]-d[0])==4)puts("minor");
    else puts("strange");
}