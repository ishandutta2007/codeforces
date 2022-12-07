#include <bits/stdc++.h>
using namespace std;
int n, *ar1, *ar2, *ar;
bool comp(int a, int b){return (ar1[a]>ar1[b]);}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    ar1=new int[n], ar2=new int[n], ar=new int[n];
    for(int a=0; a<n; a++) scanf("%d", &ar1[a]);
    for(int a=0; a<n; a++) scanf("%d", &ar2[a]);
    for(int a=0; a<n; a++) ar[a]=a;
    sort(ar, ar+n, comp);
    vector <int> an;
    an.push_back(ar[0]+1);
    for(int a=1; a<n; a+=2)
    {
        if(a==n-1) an.push_back(ar[a]+1);
        else
        {
            if(ar2[ar[a]]>ar2[ar[a+1]]) an.push_back(ar[a]+1);
            else an.push_back(ar[a+1]+1);
        }
    }
    printf("%d\n", an.size());
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}