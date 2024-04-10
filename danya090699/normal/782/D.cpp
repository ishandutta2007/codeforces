#include <bits/stdc++.h>
using namespace std;
struct el
{
    string na;
    int nu;
};
el nel;
bool comp(el a, el b){return (a.na<b.na);}
bool comp2(el a, el b){return (a.nu<b.nu);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, po=1, yk=0;
    cin>>n;
    vector <el> cl;
    char an[n];
    for(int a=0; a<n; a++)
    {
        string s1, s2;
        cin>>s1>>s2;
        nel.na=s1.substr(0, 3)+s2.substr(0, 1);
        nel.nu=a;
        cl.push_back(nel);
        an[a]=0;
    }
    sort(cl.begin(), cl.end(), comp);
    while(yk<n)
    {
        int st=yk;
        string cu=cl[yk].na.substr(0, 2);
        while(yk<n)
        {
            if(cl[yk].na.substr(0, 2)==cu) yk++;
            else break;
        }

        bool us[26], ch=1;
        for(int a=0; a<26; a++) us[a]=0;
        int yk2=st;
        vector <int> ve;
        while(yk2<yk)
        {
            int st2=yk2;
            char cu2=cl[yk2].na[2];
            while(yk2<yk)
            {
                if(cl[yk2].na[2]==cu2) yk2++;
                else break;
            }
            if(yk2-st2==1) ve.push_back(st2);
            else
            {
                for(st2; st2<yk2; st2++)
                {
                    int sy=cl[st2].na[3]-'A';
                    if(us[sy]) po=0;
                    else
                    {
                        an[cl[st2].nu]=cl[st2].na[3], us[sy]=1;
                    }
                }
            }
        }
        if(po==0) break;
        while(ch)
        {
            ch=0;
            for(int a=0; a<ve.size(); a++)
            {
                int nu=ve[a];
                int sy1=cl[nu].na[2]-'A', sy2=cl[nu].na[3]-'A', cn=cl[nu].nu;
                if(an[cn]==0)
                {
                    if(us[sy1]==0 or us[sy2]==0)
                    {
                        if(us[sy1])
                        {
                            an[cn]=cl[nu].na[3], ch=1, us[sy2]=1;
                        }
                        else if(us[sy2])
                        {
                            an[cn]=cl[nu].na[2], ch=1, us[sy1]=1;
                        }
                    }
                    else
                    {
                        ch=0, po=0;
                        break;
                    }
                }
            }
        }
        if(po==0) break;
        for(int a=0; a<ve.size(); a++)
        {
            int nu=ve[a];
            int sy=cl[nu].na[2]-'A', cn=cl[nu].nu;
            if(an[cn]==0) an[cn]=cl[nu].na[2];
        }
    }
    if(po)
    {
        sort(cl.begin(), cl.end(), comp2);
        cout<<"YES\n";
        for(int a=0; a<n; a++) cout<<cl[a].na[0]<<cl[a].na[1]<<an[a]<<"\n";
    }
    else cout<<"NO";
}