#include<bits/stdc++.h>
using namespace std;

int a[3];
map<string,int> mp;
bool u[3];
int d[3];
int cnt;

void dfs(int c){
    if(c==3){
        if((d[1]-d[0]+12)%12==4&&(d[2]-d[1]+12)%12==3){
            cout<<"major"<<endl;
            exit(0);
        }
        if((d[1]-d[0]+12)%12==3&&(d[2]-d[1]+12)%12==4){
            cout<<"minor"<<endl;
            exit(0);
        }
        return ;
    }
    for(int i=0;i<3;i++){
        if(!u[i]){
            d[c]=a[i];
            u[i]=true;
            dfs(c+1);
            u[i]=false;
        }
    }
    return ;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    mp["C"]=0;
    mp["C#"]=1;
    mp["D"]=2;
    mp["D#"]=3;
    mp["E"]=4;
    mp["F"]=5;
    mp["F#"]=6;
    mp["G"]=7;
    mp["G#"]=8;
    mp["A"]=9;
    mp["B"]=10;
    mp["H"]=11;
    string sa,sb,sc;
    cin>>sa>>sb>>sc;
    a[0]=mp[sa];
    a[1]=mp[sb];
    a[2]=mp[sc];
    dfs(0);
    cout<<"strange"<<endl;

    return 0;
}