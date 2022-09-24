#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int n;
int I[100001];

vector <long long> V;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    scanf("%d",&n);
    int i,a;
    for(i=0; i<n; i++){
        scanf("%d",&I[i]);
    }

    sort(I,I+n);

    for(i=n-1; i>=0; i--){
        if(I[i]-I[i-1]<=1){
            V.push_back(I[i-1]);
            i--;
        }
    }

    long long ans=0;
    for(i=0; i<V.size(); i+=2){
        if(i+1>=V.size()) break;
        ans += V[i]*V[i+1];
    }

    printf("%I64d\n",ans);

    return 0;
}