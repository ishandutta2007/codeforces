#include <bits/stdc++.h>
using namespace std;
int n,x,y,z,a,b,c,last;
int ans[1000001];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    last=1;
    while (true){
        if (last>n){
            cout<<"! ";
            for (int i=1;i<=n;++i)
                cout<<ans[i]<<" ";
                cout.flush();
                return 0;
        }
        if (last==1){
            cout<<"? "<<1<<" "<<2<<endl;
             cout.flush();
             //fflush(stdout);
            cin>>x;
            cout<<"? "<<1<<" "<<3<<endl;
             cout.flush();
             //fflush(stdout);
            cin>>y;
            cout<<"? "<<2<<" "<<3<<endl;
             cout.flush();
             //fflush(stdout);
            cin>>z;
            for (int i=0;i<=x;++i){
                a=i; b=x-i; c=z-b;
                if (a+b==x && b+c==z && a+c==y) break;
            }
            ans[1]=a; ans[2]=b; ans[3]=c;
            last=4;
        } else {
            cout<<"? "<<1<<" "<<last<<endl;
           cout.flush();
           // fflush(stdout);
            cin>>x;
            ans[last]=x-ans[1];
            ++last;
        }
    }
}