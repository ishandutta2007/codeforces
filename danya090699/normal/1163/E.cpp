#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int i=20; ; i--)
    {
        int ma[i], q=0;
        vector <int> sp;
        for(int b=0; b<i; b++) ma[b]=0;
        for(int a=0; a<n; a++)
        {
            if(ar[a]<(1<<i))
            {
                int x=ar[a];
                for(int b=i-1; b>=0; b--)
                {
                    if(x&(1<<b))
                    {
                        if(ma[b]&(1<<b)) x^=ma[b];
                        else
                        {
                            ma[b]=x, sp.push_back(ar[a]);
                            break;
                        }
                    }
                }
            }
        }
        if(sp.size()==i)
        {
            cout<<i<<"\n";
            int an[1<<i];
            for(int b=0; b<i; b++)
            {
                for(int c=(1<<(i-1-b)); c<(1<<i); c+=(1<<(i-b))) an[c]=sp[b];
            }
            an[0]=0;
            for(int b=1; b<(1<<i); b++) an[b]^=an[b-1];
            for(int b=0; b<(1<<i); b++) printf("%d ", an[b]);
            break;
        }
    }
}