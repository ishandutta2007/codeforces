#include <bits/stdc++.h>
using namespace std;
long long a[5];
int main(){
    long long x,y,z;
    cin>>a[0]>>a[1]>>a[2];
    long long ans=5e18;
    if (a[0]<=1 && a[1]<=1 && a[2]<=1) {
        if (a[0] && a[2]) ans=3-a[0]-a[1]-a[2];
        if (!a[0] || !a[2]) ans=0;
    }
    for (int i=1;i<=3;++i) {
        for (int j=1;j<=3;++j) {
            x=a[0];
            y=a[1];
            z=a[2];
            long long sum=0;
            if (i<=1) if (x) --x; else ++sum;
            if (i<=2) if (y) --y; else ++sum;
            if (i<=3) if (z) --z; else ++sum;
            if (j>=3) if (z) --z; else ++sum;
            if (j>=2) if (y) --y; else ++sum;
            if (j>=1) if (x) --x; else ++sum;
                ans=min(ans,max(x,max(y,z))*(long long)3-x-y-z+sum);
        }
    }
    cout<<ans;
}