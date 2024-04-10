#include <bits/stdc++.h>

using namespace std;

int n;
char a[1000][1000];
char d[1000];
int maxy(0);
int kilk(0);
int posx(0);
int posy(0);
bool t=false;
bool tt=false;
stack<pair<int,int> > st;

struct dyzhka
{
          int x1,y1,x2,y2;
};

vector<dyzhka> ans;

void zapus(int x1,int y1,int x2,int y2)
{
          a[x1][y1]='+';
          a[x1][y2]='+';
          a[x2][y1]='+';
          a[x2][y2]='+';
          a[x1][y1+1]='-';
          a[x1][y2-1]='-';
          a[x2][y1+1]='-';
          a[x2][y2-1]='-';
          for(int i=x1+1;i<=x2-1;i++)
          {
                    a[i][y1]='|';
                    a[i][y2]='|';
          }

}

void vuvid(int n,int m)
{
          for(int i=0;i<n;i++)
          {
                    for(int j=0;j<m;j++)
                              cout<<a[i][j];
                    cout<<endl;
          }
}

int main()
{
          //freopen("output.txt","w",stdout);
         // freopen("input.txt","r",stdin);
          memset(a,' ',sizeof(a));
          cin>>n;
          for(int i=0;i<n;i++)
                    cin>>d[i];
          for(int i=0;i<n;i++)
          {
                    if(d[i]=='[')
                              kilk++;
                    else
                              kilk--;
                    maxy=max(kilk,maxy);
          }
          maxy=maxy*2;
          for(int i=0;i<n;i++)
          {
                    if(d[i]=='[')
                    {
                              st.push(make_pair(posx,posy));
                              posx++;
                              posy++;
                              t=true;
                    }
                    else
                    {
                              if(t)
                              {
                                        pair<int,int> k=st.top();
                                        st.pop();
                                        dyzhka s;
                                        s.x1=k.first;
                                        s.y1=k.second;
                                        s.x2=posx+3;
                                        posx+=4;
                                        posy--;
                                        s.y2=maxy-k.second;
                                        ans.push_back(s);
                                        t=false;
                              }
                              else
                              {
                                        pair<int,int> k=st.top();
                                        st.pop();
                                        dyzhka s;
                                        s.x1=k.first;
                                        s.y1=k.second;
                                        s.x2=posx;
                                        posx+=1;
                                        posy--;
                                        s.y2=maxy-k.second;
                                        ans.push_back(s);
                              }
                    }
          }
         // for(int i=0;i<ans.size();i++)
         //           cout<<ans[i].x1<<" "<<ans[i].y1<<" "<<ans[i].x2<<" "<<ans[i].y2<<endl;
          for(int i=0;i<ans.size();i++)
                    zapus(ans[i].y1,ans[i].x1,ans[i].y2,ans[i].x2);
          vuvid(maxy+1,posx);


}