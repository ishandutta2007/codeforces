#include <bits/stdc++.h>
using namespace std;


string q[100];
map<pair<string,string>,int> d;
string x,y,z;

inline void chek(string x,string y,string z){
    if (d[make_pair(x,y)]==3 && d[make_pair(y,z)]==4) {
        cout<<"minor";
        exit(0);
    }
    if (d[make_pair(x,y)]==4 && d[make_pair(y,z)]==3) {
        cout<<"major";
        exit(0);
    }
}
int main(){
    //
    q[0]="C";
    q[1]="C#";
    q[2]="D"; q[3]="D#";
    q[4]="E"; q[5]="F";
    q[6]="F#"; q[7]="G"; q[8]="G#";
    q[9]="A"; q[10]="B"; q[11]="H";
    for (int i=12;i<=23;++i)
        q[i]=q[i-12];
    for (int i=0;i<=11;++i)
        for (int j=i+1;j<=i+11;++j)
            d[make_pair(q[i],q[j])]=j-i;
    cin>>x>>y>>z;
    chek(x,y,z);
    chek(x,z,y);
    chek(y,x,z);
    chek(y,z,x);
    chek(z,x,y);
    chek(z,y,x);
    cout<<"strange";
}