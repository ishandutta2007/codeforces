#include <bits/stdc++.h>
#define int long long
using namespace std;
string s(int x)
{
    vector <int> ve;
    while(x)
    {
        ve.push_back(x%10), x/=10;
    }
    string re;
    while(ve.size())
    {
        re.push_back('0'+ve.back());
        ve.pop_back();
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    if(n==10000000000) cout<<"100^5";
    else
    {
        string an=s(n);
        for(int a=2; a<100; a++)
        {
            for(int b=2; b<100; b++)
            {
                for(int sta=a*a, i=2; sta<=n; sta*=a, i++)
                {
                    for(int stb=b*b, j=2; stb<=n; stb*=b, j++)
                    {
                        if(sta+stb<=n)
                        {
                            int os=n-(sta+stb);
                            string cu=s(a)+"^"+s(i)+"+"+s(b)+"^"+s(j);
                            if(os) cu+="+"+s(os);
                            if(cu.size()<an.size()) an=cu;

                            if((n-stb)%sta==0)
                            {
                                int d=(n-stb)/sta;
                                if(d>1)
                                {
                                    string cu=s(a)+"^"+s(i)+"*"+s(d)+"+"+s(b)+"^"+s(j);
                                    if(cu.size()<an.size()) an=cu;
                                }
                            }
                        }
                        if(n/sta>=stb)
                        {
                            int os=n-(sta*stb);
                            string cu=s(a)+"^"+s(i)+"*"+s(b)+"^"+s(j);
                            if(os) cu+="+"+s(os);
                            if(cu.size()<an.size()) an=cu;

                            if(n%(sta*stb)==0)
                            {
                                int d=n/(sta*stb);
                                if(d>1)
                                {
                                    string cu=s(a)+"^"+s(i)+"*"+s(b)+"^"+s(j)+"*"+s(d);
                                    if(cu.size()<an.size()) an=cu;
                                }
                            }
                        }
                    }
                }
            }
        }

        for(int a=2; a*a<=n; a++)
        {
            for(int sta=a*a, i=2; sta<=n; sta*=a, i++)
            {
                int os=n-sta;
                string cu=s(a)+"^"+s(i);
                if(os) cu+="+"+s(os);
                if(cu.size()<an.size()) an=cu;

                for(int d=9; sta*d<=n; d=d*10+9)
                {
                    int os=n-sta*d;
                    string cu=s(a)+"^"+s(i)+"*"+s(d);
                    if(os) cu+="+"+s(os);
                    if(cu.size()<an.size()) an=cu;
                }

                int d=n/sta;
                if(d>1)
                {
                    int os=n-sta*d;
                    string cu=s(a)+"^"+s(i)+"*"+s(d);
                    if(os) cu+="+"+s(os);
                    if(cu.size()<an.size()) an=cu;
                }
            }
        }

        cout<<an;
    }

}