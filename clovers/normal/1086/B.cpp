#include<bits/stdc++.h>
using namespace std;
const int N=120000;
double s;
int n,in[N];

int main()
{
    scanf("%d%lf",&n,&s);
    for(int i=1;i<n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        in[x]++,in[y]++;
    }
    double sum=0;
    for(int i=1;i<=n;i++) if(in[i]==1) sum+=1;
    printf("%.12lf",2.0*s/(1.0*sum));
    return 0;
}