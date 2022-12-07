#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q, up=0, down=0;
    cin>>n>>q;
    int ar[n], us[n], an3[n][2], an4[n][4];
    vector <int> mi, mi2, ma, ma2;
    set <int> se;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(a)
        {
            if(ar[a]>ar[a-1]) down=a;
            if(ar[a]<ar[a-1]) up=a;
        }
        an3[a][0]=min(up, down);
        an3[a][1]=a;
        if(a and an3[a][0]<an3[a-1][0])
        {
            an3[a][0]=an3[a-1][0];
            an3[a][1]=an3[a-1][1];
        }
        while(mi.size() and ar[mi.back()]>ar[a])
        {
            us[mi.back()]--;
            if(us[mi.back()]==0) se.insert(mi.back());
            mi.pop_back();
        }
        while(mi2.size() and ar[mi2.back()]>=ar[a]) mi2.pop_back();

        while(ma.size() and ar[ma.back()]<ar[a])
        {
            us[ma.back()]--;
            if(us[ma.back()]==0) se.insert(ma.back());
            ma.pop_back();
        }
        while(ma2.size() and ar[ma2.back()]<=ar[a]) ma2.pop_back();

        an4[a][0]=-1;
        if(mi2.size() and ma2.size())
        {
            auto it=se.lower_bound(min(mi2.back(), ma2.back()));
            if(it!=se.begin())
            {
                it--;
                an4[a][0]=(*it);
                int pmi=upper_bound(mi.begin(), mi.end(), an4[a][0])-mi.begin();
                an4[a][1]=mi[pmi];
                int pma=upper_bound(ma.begin(), ma.end(), an4[a][0])-ma.begin();
                an4[a][2]=ma[pma];

                if(an4[a][1]>an4[a][2]) swap(an4[a][1], an4[a][2]);
                an4[a][3]=a;
            }
        }
        if(a and an4[a-1][0]>an4[a][0])
        {
            for(int i=0; i<4; i++) an4[a][i]=an4[a-1][i];
        }

        us[a]=2;
        mi.push_back(a), mi2.push_back(a);
        ma.push_back(a), ma2.push_back(a);
    }
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        if(an4[r][0]>=l)
        {
            printf("4\n");
            for(int i=0; i<4; i++) printf("%d ", an4[r][i]+1);
            printf("\n");
        }
        else if(an3[r][0]>l)
        {
            printf("3\n%d %d %d\n", an3[r][0], an3[r][0]+1, an3[r][1]+1);
        }
        else printf("0\n");
    }
}