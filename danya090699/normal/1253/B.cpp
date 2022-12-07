#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
bool us[sz];
void err()
{
    cout<<-1;
    exit(0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    vector <int> sp, an;
    for(int a=0; a<n; a++)
    {
        int i;
        scanf("%d", &i);
        if(i<0)
        {
            if(us[-i]) us[-i]=0, q--;
            else err();
        }
        else
        {
            if(us[i]) err();
            else us[i]=1, sp.push_back(i), q++;
        }
        if(q==0)
        {
            set <int> se;
            for(int b=0; b<sp.size(); b++) se.insert(sp[b]);
            if(se.size()==sp.size())
            {
                an.push_back(sp.size()*2);
                sp.clear();
            }
            else err();
        }
    }
    if(q) err();
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d ", an[a]);
}