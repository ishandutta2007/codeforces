#include<bits/stdc++.h>

using namespace std;

int t;
vector<long long> v;
long long p10[20];

long long calc(long long q){
    int p=lower_bound(v.begin(),v.end(),q+1)-v.begin()-1;
    return p;
}
int main(){
    ios::sync_with_stdio(0);
    p10[0]=1;
    for(int i=1;i<19;i++) p10[i]=p10[i-1]*10;
    v.push_back(0);
    for(int i=0;i<=18;i++){
        for(int x=0;x<10;x++){
            int f1=x%10;
            if(f1==0) continue;
            v.push_back(p10[i]*f1);
        }
    }
    for(int i=0;i<=18;i++){
        for(int j=i+1;j<=18;j++){
            for(int x=0;x<100;x++){
                int f1=x%10;
                int f2=(x/10)%10;
                if(f1==0||f2==0) continue;
                v.push_back(p10[i]*f1+p10[j]*f2);
            }
        }
    }
    for(int i=0;i<=18;i++){
        for(int j=i+1;j<=18;j++){
            for(int k=j+1;k<=18;k++){
                for(int x=0;x<1000;x++){
                    int f1=x%10;
                    int f2=(x/10)%10;
                    int f3=(x/100)%10;
                    if(f1==0||f2==0||f3==0) continue;
                    v.push_back(p10[i]*f1+p10[j]*f2+p10[k]*f3);
                }
            }
        }
    }
    sort(v.begin(),v.end());
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<'\n';
    }

    return 0;
}