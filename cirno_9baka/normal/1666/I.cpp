#include<bits/stdc++.h>
using namespace std;
const int N=105,M=998244353,E=502;
const long long inf=5000000000000000000ll;
int n,m,t,x[2],y[2],s1,s2,u1,u2,p1,p2;
bool DG(int x,int y){
    cout<<"DIG "<<x<<' '<<y<<endl;
    cin>>x;
    return x;
}
int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        cout<<"SCAN 1 1"<<endl;
        cin>>s1;
        cout<<"SCAN "<<n<<' '<<1<<endl;
        cin>>s2;
        s1+=4;
        s2+=2-2*n;
        u2=(s1+s2)/2;
        u1=(s1-s2)/2;
        cout<<"SCAN "<<u1/2<<' '<<1<<endl;
        cin>>p1;
        cout<<"SCAN "<<1<<' '<<u2/2<<endl;
        p1+=2-u2;
        x[0]=(p1+u1)/2;
        x[1]=(u1-p1)/2;
        cin>>p2;
        p2+=2-u1;
        y[0]=(p2+u2)/2;
        y[1]=(u2-p2)/2;
        if(DG(x[0],y[0]))
            DG(x[1],y[1]);
        else
            DG(x[0],y[1]),DG(x[1],y[0]);
    }
}