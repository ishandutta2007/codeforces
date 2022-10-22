#include <iostream>
#include <vector>
using namespace std;
int main(){
    int h1,a1,c1,h2,a2;
    cin>>h1>>a1>>c1>>h2>>a2;
    vector<string> a;
    while(h2>0){
        if(h1>a2||h2<=a1){
            a.push_back("STRIKE");
            h2-=a1;
            h1-=a2;
        }else{
            a.push_back("HEAL");
            h1-=a2;
            h1+=c1;
        }
    }
    cout<<a.size()<<"\n";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\n";
    }
    return 0;
}