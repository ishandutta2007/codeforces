#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
int goal;

int digits(ll x){
    int res=0;
    while(x>0){
        x/=10;
        res++;
    }
    return res;
}

void dfs(int dep,ll cur,int c4){
    //cout<<dep<<' '<<cur<<' '<<c4<<endl;
    if(dep==goal){
        if(cur>=n&&c4==goal/2){
            cout<<cur<<endl;
            exit(0);
        }
        return;
    }
    if(c4<goal/2){
        cur=cur*10+4;
        dfs(dep+1,cur,c4+1);
        cur+=3;
        dfs(dep+1,cur,c4);
    }else{
        cur=cur*10+7;
        dfs(dep+1,cur,c4);
    }
    
    return;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    goal=digits(n);
    if(goal%2==1)goal++;
    //cout<<goal<<endl;
    dfs(0,0,0);//cout<<"stane"<<endl;
    goal+=2;
    dfs(0,0,0);

    return 0;
}