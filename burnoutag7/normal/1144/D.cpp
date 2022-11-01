#include<bits/stdc++.h>
using namespace std;

struct stane{
    int type;
    int i,j;
};

int n;
map<int,int> mp;
int a[200005];
int mx,res,pos;
vector<stane> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>mx){
            mx=it->second;
            res=it->first;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]==res){
            pos=i;
            break;
        }
    }
    for(int i=pos-1;i>=1;i--){
        if(a[i]==a[i+1]){
            continue;
        }
        stane shit;
        if(a[i]<a[i+1]){
            shit.type=1;
            shit.i=i;
            shit.j=i+1;
            a[i]=a[i+1];
        }
        if(a[i]>a[i+1]){
            shit.type=2;
            shit.i=i;
            shit.j=i+1;
            a[i]=a[i+1];
        }
        v.push_back(shit);
    }
    for(int i=pos+1;i<=n;i++){
        if(a[i]==a[i-1]){
            continue;
        }
        stane shit;
        if(a[i-1]>a[i]){
            shit.type=1;
            shit.i=i;
            shit.j=i-1;
            a[i]=a[i-1];
        }
        if(a[i-1]<a[i]){
            shit.type=2;
            shit.i=i;
            shit.j=i-1;
            a[i]=a[i-1];
        }
        v.push_back(shit);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].type<<' '<<v[i].i<<' '<<v[i].j<<endl;
    }

    return 0;
}