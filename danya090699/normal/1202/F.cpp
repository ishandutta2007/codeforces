#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int qa, qb, an=0;
    cin>>qa>>qb;
    int n=qa+qb, sq=ceil(sqrt(n));
    vector <int> bl;
    for(int a=1; n/a>sq; a++)
    {
        if(bl.size()==0 or bl.back()!=n/a) bl.push_back(n/a);
    }
    for(int a=sq; a; a--) bl.push_back(a);
    for(int a=0; a<bl.size(); a++)
    {
        int bq=bl[a];
        if(qa/bq>=qa%bq and qb/bq>=qb%bq)
        {
            int ra=qa/bq, la=qa/(bq+1)+1, rb=qb/bq, lb=qb/(bq+1)+1;
            if(qa%(bq+1)==0) la--;
            if(qb%(bq+1)==0) lb--;
            if(qa/ra and rb)
            {
                int r=ra+rb, l=la+lb;
                if(qa%(bq+1)==0 and qb%(bq+1)==0) l++;
                an+=(r-l+1);
            }
        }
    }
    cout<<an;
}