#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <int, greater <int> > se;
    set <int> mo, sh;
    auto it=se.begin();
    long long tot=0, prefq=0, prefsu=0;
    for(int a=0; a<n; a++)
    {
        int ty, w;
        scanf("%d%d", &ty, &w);
        int x=(it==se.end()) ? -1 : (*it);
        if(w<0 and x==-w)
        {
            prefq++, prefsu+=x, it++;
        }
        x=(it==se.end()) ? -1 : (*it);

        if(w>0)
        {
            se.insert(w);
            if(w>x) prefq++, prefsu+=w;

            if(ty==0) sh.insert(w);
            else mo.insert(w);

            tot+=w;
        }
        else
        {
            se.erase(-w);
            if(-w>x) prefq--, prefsu-=(-w);

            if(ty==0) sh.erase(-w);
            else mo.erase(-w);

            tot+=w;
        }

        while(prefq<mo.size())
        {
            prefsu+=(*it), prefq++, it++;
        }
        while(prefq>mo.size())
        {
            it--, prefsu-=(*it), prefq--;
        }

        if(mo.size())
        {
            long long an=tot+prefsu;
            it--;
            if((*it)<=(*mo.begin()))
            {
                an-=*mo.begin();

                auto it2=sh.lower_bound(*it);
                if(it2!=sh.begin())
                {
                    it2--, an+=(*it2);
                }
            }
            it++;

            printf("%lld\n", an);
        }
        else printf("%lld\n", tot);
    }
}