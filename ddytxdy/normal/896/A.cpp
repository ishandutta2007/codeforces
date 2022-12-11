#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int q,n,l1=34,l2=32,l3=2;LL k,len[N],L1[N],L2[N],L3[N],L4[N],L5[N];
string s,t1,t2,t3;
int main(){
    s="What are you doing at the end of the world? Are you busy? Will you save us?";
    // t="What are you doing while sending ""? Are you busy? Will you send ""?";//cout<<t.length();
    t1="What are you doing while sending \"";t2="\"? Are you busy? Will you send \"";t3="\"?";
    // t="\"? Are you busy? Will you send \"";cout<<t.length()<<endl;
    L5[1]=s.length();//cout<<len[1];
    // cout<<s.length()<<" ";
    for(int i=2;i<=100;i++){
        L1[i]=l1;L2[i]=L1[i]+L5[i-1];L3[i]=L2[i]+l2;L4[i]=L3[i]+L5[i-1];L5[i]=L4[i]+l3;
    }
    for(int i=57;i<N;i++)L1[i]=l1,L2[i]=L2[i-1];
    scanf("%d",&q);
    while(q--){
        scanf("%d%lld",&n,&k);n++;
        if(n<=56&&L5[n]<k){cout<<'.';continue;}
        for(int i=n;i;i--){
            if(i==1){cout<<s[k-1];break;}
            if(k<=L1[i]){cout<<t1[k-1];break;}
            if(k<=L2[i]){k-=L1[i];continue;}
            if(k<=L3[i]){cout<<t2[k-L2[i]-1];break;}
            if(k<=L4[i]){k-=L3[i];continue;}
            cout<<t3[k-L4[i]-1];break;
        }
    }
    return 0;
}