#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        long long p,f,cnt1,cnt2,s,w;
        scanf("%lld%lld%lld%lld%lld%lld",&p,&f,&cnt1,&cnt2,&s,&w);
        if(s>w){
            swap(s,w);
            swap(cnt1,cnt2);
        }
        int ans=0;
        for(int i=0;i<=cnt1;i++)
        {
            if(1LL*i*s>p) break;
            int cnt=i;
            long long rp=cnt1-i,rw=cnt2,a=p-i*s,b;
            int x=min(rw,a/w);
            rw-=x;
            cnt+=x;
            if(f>=rp*s){
                b=f-rp*s;
                cnt+=rp;
                x=min(rw,b/w);
                cnt+=x;
            }
            else{
                cnt+=f/s;
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}