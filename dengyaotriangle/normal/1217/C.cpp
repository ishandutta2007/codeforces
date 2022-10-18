#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=200005;

char x[maxn];
int n;
set<pair<int,int> > s;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>(x+1);
        n=strlen(x+1);
        long long cnt=0;
        s.clear();
        for(int i=1;i<20;i++){
            int pf0=0;
            for(int j=1;j<=n-i+1;j++){
                if(x[j]=='1'){
                    int cur=0;
                    for(int k=j;k<=j+i-1;k++){
                        cur<<=1;
                        cur+=x[k]-'0';
                    }
                    if(pf0+i>=cur)cnt++;
                    pf0=0;
                }else pf0++;
            }
        }
        cout<<cnt<<'\n';
    }
    return 0;
}