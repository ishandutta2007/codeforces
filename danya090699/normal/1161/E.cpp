#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
char s[sz];
main()
{
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n;
        cin>>n;
        int pr[n][2];
        for(int i=0; i<2; i++)
        {
            if(n>i+1)
            {
                printf("Q %d", (n-i)/2);
                for(int a=i; a+1<n; a+=2) printf(" %d %d", a+1, a+2);
                cout<<endl;
                scanf("%s", s);
                int yk=0;
                for(int a=i+1; a<n; a+=2) pr[a][0]=s[yk++]-'0';
            }
        }
        vector <pair <int, int> > sp;
        sp.push_back({0, 1});
        for(int a=1; a<n; a++)
        {
            if(pr[a][0]) sp.back().second++;
            else sp.push_back({a, 1});
        }
        for(int i=2; i<=4; i+=2)
        {
            if(sp.size()>i)
            {
                printf("Q %d", (sp.size()-i+3)/4+(sp.size()-i-1+3)/4);
                for(int a=i; a<sp.size(); a+=4)
                {
                    printf(" %d %d", sp[a].first+1, sp[a-2].first+1);
                    if(a+1<sp.size()) printf(" %d %d", sp[a+1].first+1, sp[a-1].first+1);
                }
                cout<<endl;
                scanf("%s", s);
                int yk=0;
                for(int a=i; a<sp.size(); a+=4)
                {
                    pr[sp[a].first][1]=s[yk++]-'0';
                    if(a+1<sp.size()) pr[sp[a+1].first][1]=s[yk++]-'0';
                }
            }
        }
        int c[2]={0, 1};
        vector <int> an[3];
        for(int i=0; i<min(2, int(sp.size())); i++)
        {
            for(int a=sp[i].first; a<sp[i].first+sp[i].second; a++) an[i].push_back(a);
        }
        for(int a=2; a<sp.size(); a++)
        {
            int p=sp[a].first, cu;
            if(pr[p][0]) cu=c[1];
            else if(pr[p][1]) cu=c[0];
            else
            {
                if(min(c[0], c[1])==1) cu=0;
                else if(max(c[0], c[1])==1) cu=2;
                else cu=1;
            }
            c[0]=c[1], c[1]=cu;
            for(int b=p; b<p+sp[a].second; b++) an[cu].push_back(b);
        }
        cout<<"A "<<an[0].size()<<" "<<an[1].size()<<" "<<an[2].size()<<endl;
        for(int i=0; i<3; i++)
        {
            for(int a=0; a<an[i].size(); a++) printf("%d ", an[i][a]+1);
            cout<<endl;
        }
    }
}