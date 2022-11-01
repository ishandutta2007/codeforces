#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    scanf("%d",&k);
    if(!(k&1))
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    vector<pair<int,int>> edges={{1,2*k}};
    auto add=[&](int a,int b)->void
    {
        edges.push_back({a,b});
        edges.push_back({a+2*k-1,b+2*k-1});
    };
    for(int i=2;i<=k;i++) add(1,i);
    for(int i=2;i<=k;i++) for(int j=k+1;j<=2*k-1;j++) add(i,j);
    for(int j=k+1;j<=2*k-1;j+=2) add(j,j+1);
    printf("%d %d\n",4*k-2,k*(4*k-2)/2);
    for(auto [a,b]:edges) printf("%d %d\n",a,b);
    return 0;
}