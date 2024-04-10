#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define MAX 25
#define REP(x,y) for(int x=0;x<y;x++)
//#define REP(x,y,z) for(int x=y;x<z;x++)
#define MEM(x,y) memset(x,y,sizeof x)
#define a first
#define b second
int main()
{
    int m;
    while(scanf("%d",&m)==1)
    {
        string s;
        cin>>s;
        set<int> st;
        for(int i=0;i<26;i++)
        {
            int n=0;
            for(int j=0;j<s.length();j++)
                if(s[j]=='a'+i)st.insert(j),n++;
            if(!n)continue;
            int e=-1,gg=0;
            set<int>::iterator it;
            for(it=st.begin();it!=st.end();it++)
            {
                if(*it-e>m)gg=1;
                e=*it;
            }
            if(e+m<s.length())gg=10;
//            cout<<gg<<"  "<<e<<"   "<<m<<endl;
            if(gg)continue;

//            for(it=st.begin();it!=st.end();it++)
//                    cout<<*it<<" ";cout<<endl;



            for(int j=0;j<s.length();j++)
            {
                if(s[j]!='a'+i)continue;
                set<int>::iterator ff,bb;
                ff=st.lower_bound(j);
                bb=st.upper_bound(j);
                int fr,ba;
                if(ff==st.begin())fr=-1;
                else ff--,fr=*ff;
                if(bb==st.end())ba=-1;
                else ba=*bb;

                if(fr==-1 && ba==-1);
                else if(fr==-1)
                {
                    if(ba<m)st.erase(j);
                }
                else if(ba==-1)
                {
                    if(fr+m>=s.length())st.erase(j);
                }
                else if(ba-fr<=m)st.erase(j);
            }
            break;
        }
        vector<char> vb;
        set<int>::iterator it;
        for(it=st.begin();it!=st.end();it++)
            vb.push_back(s[*it]);
        sort(vb.begin(),vb.end());
        for(int i=0;i<vb.size();i++)
            printf("%c",vb[i]);puts("");

    }
    return 0;
}