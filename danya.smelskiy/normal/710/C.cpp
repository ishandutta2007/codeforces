#include <bits/stdc++.h>
using namespace std;


int n;

int main(){
    cin>>n;
    int l=n/2+1;
    int r=l;
    int last1=1,last2=2;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j)
        if (j>=l && j<=r)  {
            cout<<last1<<" ";
            last1+=2;
        } else {
            cout<<last2<<" ";
            last2+=2;
        }
        if (i==n/2+1) l=2,r=n-1;
        else if (i<=n/2) l--,r++;
        else ++l,--r;
        cout<<'\n';
    }
}