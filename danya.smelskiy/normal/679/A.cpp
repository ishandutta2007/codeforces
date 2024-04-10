#include <bits/stdc++.h>
using namespace std;

int n;
int q[105];
int sz;

inline bool f(int x){
    cout<<x<<endl;
    string res;
    cin>>res;
    return res=="yes";
}

int main(){
    n=50;
    for (int i=2;i<=n;++i) {
        bool t=false;
        for (int j=2;j<=sqrt(i);++j)
        if (i%j==0) {
            t=true;
            break;
        }
        if (t==false) {
            q[++sz]=i;
        }
    }
    int kol=0;
    int qq[100];
    for (int i=1;i<=4;++i)
    if (f(q[i])) {
        qq[++kol]=i;
    }
    if (kol>1) {
        cout<<"composite"<<endl;
        return 0;
    }
    if (kol==0) {
        cout<<"prime"<<endl;
        return 0;
    }
    int x=qq[1];
    for (int j=x;j<=sz && q[x]*q[j]<=100;++j)
    if (f(q[x]*q[j])) {
        cout<<"composite"<<endl;
        return 0;
    }
    cout<<"prime"<<endl;
}