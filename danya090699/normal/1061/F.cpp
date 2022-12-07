#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n, k, h=0, cu=1, su=0;
    string re;
    cin>>n>>k;
    while(su<n) su+=cu, h++, cu*=k;
    while(1)
    {
        int u=rand()%n+1, v=rand()%n+1;
        vector <int> sp;
        for(int a=1; a<=n; a++)
        {
            printf("? %d %d %d", u, a, v);
            cout<<endl;
            cin>>re;
            if(re=="Yes") sp.push_back(a);
        }
        if(sp.size()==h*2-1)
        {
            for(int a=0; a<sp.size(); a++)
            {
                int q=0;
                for(int b=0; b<sp.size(); b++)
                {
                    printf("? %d %d %d", u, sp[b], sp[a]);
                    cout<<endl;
                    cin>>re;
                    if(re=="Yes") q++;
                }
                if(q==h)
                {
                    cout<<"! "<<sp[a]<<endl;
                    break;
                }
            }
            break;
        }
    }
}