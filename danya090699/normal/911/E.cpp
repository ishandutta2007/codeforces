#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], us[n+1], yk=0, er=0;
    vector <int> st;
    for(int a=1; a<=n; a++) us[a]=0;
    for(int a=0; a<k; a++)
    {
        cin>>ar[a];
    }
    for(int a=1; a<=n; a++)
    {
        if(us[a])
        {
            if(st.back()==a) st.pop_back();
            else er=1;
        }
        else
        {

            while(yk<k)
            {
                if(ar[yk]==a) break;
                else
                {
                    if(st.size())
                    {
                        if(ar[yk]<st.back())
                        {
                            us[ar[yk]]=1, st.push_back(ar[yk]), yk++;
                        }
                        else
                        {
                            er=1;
                            break;
                        }
                    }
                    else
                    {
                        us[ar[yk]]=1, st.push_back(ar[yk]), yk++;
                    }
                }
            }
            if(er) break;
            if(yk<k) yk++;
            else
            {
                int x=n;
                if(st.size()) x=st.back()-1;
                for(int b=x; b>=a; b--)
                {
                    ar[yk]=b, yk++;
                }
                a=x;
            }
        }
        if(er) break;

    }
    if(er==0)
    {
        for(int a=0; a<n; a++) cout<<ar[a]<<" ";
    }
    else cout<<-1;
}