#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
              int a,b;
              cin>>a>>b;
              string s;
              cin>>s;
              int b2=0,tot=0,tar=-1;
              bool ext=0;
              for(int i=0;i<s.length();i++)
              {
                      int j=i;
                      int cur=0;
                      while(s[j]=='.'&&j<s.length())
                      {
                                                    j++;
                                                    cur++;
                      }
                      if(cur>=2*b)
                      {
                            b2++;
                            tar=cur;
                      }
                      if(cur>=b&&cur<a)
                          ext=1;
                      if(cur>=a) tot++;
                      i=max(i,j-1);
              }
              //cout<<b2<<","<<tot<<endl;
              if(b2>=2||ext)
              {
                       cout<<"No"<<endl;                   
              }
              else if(b2==0)
              {
                   if(tot&1) cout<<"Yes"<<endl;
                   else cout<<"No"<<endl;    
              }
              else{
                   if(a>tar) cout<<"No"<<endl;
                   else{
                       tot--;
                        bool ok=0;
                        for(int i=0;i<=tar-a;i++)
                        {
                            int oth=tar-i-a;
                            int curcnt=tot;
                            if(oth>=b&&oth<a) continue;
                            if(i>=b&&i<a) continue;
                            if(oth>=2*b||i>=2*b) continue;
                            if(oth>=a) curcnt++;
                            if(i>=a) curcnt++;
                            if(!(curcnt&1)){
                                //cout<<i<<" "<<oth<<endl;
                                ok=1;
                                break;
                            }
                        }
                        if(ok) cout<<"Yes"<<endl;
                        else cout<<"No"<<endl;
                   }
              }
    }
}