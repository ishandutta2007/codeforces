#include<bits/stdc++.h>
using namespace std;

int mem[20000005];
vector<int> p;

int get(int x){
    if(mem[x])return mem[x];
    int &ans=mem[x]=1;
    for(int i=0;p[i]*p[i]<=x;i++)if(x%p[i]==0){
        ans<<=1;
        while(x%p[i]==0)x/=p[i];
    }
    ans<<=x>1;
    return ans;
}

void mian(){
    int c,d,x;
    cin>>c>>d>>x;
    long long ans=0;
    for(int i=1;i*i<=x;i++)if(x%i==0){
        if((x/i+d)%c==0)ans+=get((x/i+d)/c);
        if((i+d)%c==0&&i*i!=x)ans+=get((i+d)/c);
    }
    cout<<ans<<'\n';
}

bool pd[4505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=2;i<=4500;i++)if(!pd[i]){
        for(int j=i+i;j<=4500;j+=i)pd[j]=1;
        p.emplace_back(i);
    }

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}