#include <bits/stdc++.h>
using namespace std;
bool ok(int l, int A, int B)
{
    if(l>=B and l<A) return false;
    if(l>=2*B) return false;
    else return true;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int A, B, bad=0, smq=0, bgq=0, l, an=0;
        string s;
        cin>>A>>B>>s;
        int yk=0;
        while(yk<s.size())
        {
            if(s[yk]=='X') yk++;
            else
            {
                int cu=0;
                while(yk<s.size() and s[yk]=='.') yk++, cu++;
                if(cu<A and cu>=B) bad=1;
                if(cu>=A and cu<2*B) smq++;
                if(cu>=2*B) bgq++, l=cu;
            }
        }
        if(bad==0)
        {
            if(bgq==0) an=(smq&1);
            else if(bgq==1)
            {
                for(int a=0; a+A<=l; a++)
                {
                    int ll=a, rr=l-a-A;
                    if(ok(ll, A, B) and ok(rr, A, B))
                    {
                        int cu=smq+(ll>=A)+(rr>=A);
                        if((cu&1)==0) an=1;
                    }
                }
            }
        }
        if(an) printf("YES\n");
        else printf("NO\n");
    }
}