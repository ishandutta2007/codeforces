#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

int app[100005];
int arr[100005];

int n,m,t;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    scanf("%d %d %d",&n,&m,&t);

    int i,a,k;
    long long ans=0;
    for(i=0; i<n; i++){
        scanf("%d",&a);
        app[a] = i+1; arr[i+1] = a;
    }
    for(i=0; i<m; i++){
        scanf("%d",&a);
        if(app[a] > 1){
            k = app[a];
            ans += (k-1)/t;
            app[a] --;
            app[arr[k-1]]++;
            a = arr[k-1];
            arr[k-1] = arr[k];
            arr[k] = a;
        }
    }

    printf("%lld\n",ans+m);

    return 0;
}