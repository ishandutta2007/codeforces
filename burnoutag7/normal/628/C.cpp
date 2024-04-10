#include<bits/stdc++.h>
using namespace std;

int n,k;
string s,t;

int dist(char c1,char c2){
    return abs(c1-c2);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    cin>>s;
    t=s;
    for(int i=0;i<n;i++){
        int res=-1;char cur;
        for(char j='a';j<='z';j++){
            int tmp=dist(s[i],j);
            if(tmp<=k&&res<tmp){
                res=tmp;
                cur=j;
            }
        }
        t[i]=cur;
        k-=res;
    }
    if(k){
        cout<<-1<<endl;
    }else{
        cout<<t<<endl;
    }

    return 0;
}