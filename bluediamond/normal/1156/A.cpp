#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100+7;
int n;
int v[N];

void e()
{
        cout<<"Infinite\n";
        exit(0);
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        int r=0;
        for(int i=2;i<=n;i++)
        {
                if((v[i-1]==2 && v[i]==3) || (v[i-1]==3 && v[i]==2))
                {
                        cout<<"Infinite\n";
                        return 0;
                }
                if(v[i]==1)
                {
                        if(v[i-1]==2)
                        {
                                r+=3;
                        }
                        else
                        {
                                r+=4;
                        }
                }
                else
                {
                        if(v[i]==2)
                        {
                                if(v[i-2]==3)
                                {
                                        r+=2;
                                }
                                else
                                {
                                        r+=3;
                                }
                        }
                        else
                        {
                                r+=4;
                        }
                }
        }
        cout<<"Finite\n"<<r<<"\n";
        return 0;
}
/**

**/