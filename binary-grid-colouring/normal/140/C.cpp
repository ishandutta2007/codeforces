#include<bits/stdc++.h>

using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;

std::map<int, int> mp;
priority_queue<pair<int,int> > Q;
pair<int,int>t1,t2,t3;
vector<pair<pair<int,int>,int> > ans;
int main(int argc, char const *argv[]) {

   int n;
   cin>>n;
   int x;
   for(int i=0;i<n;i++) {
     cin>>x;
     mp[x] ++;
   }
   for(auto x:mp){
     Q.push(make_pair(x.second,x.first));
   }
   while(1){
     if(Q.size()<3)break;
     t1 = Q.top();
     Q.pop();
     t2 = Q.top();
     Q.pop();
     t3 = Q.top();
     Q.pop();
     std::vector<int> v;
     v.push_back(t1.second);
     v.push_back(t2.second);
     v.push_back(t3.second);
     sort(v.begin(),v.end());
     ans.push_back(make_pair(make_pair(v[2],v[1]),v[0]));
     if(t1.first > 1) Q.push(make_pair(t1.first - 1,t1.second));
     if(t2.first > 1) Q.push(make_pair(t2.first - 1,t2.second));
     if(t3.first > 1) Q.push(make_pair(t3.first - 1,t3.second));
   }
   std::cout << (int)ans.size() << '\n';
   for(int i=0;i<(int)ans.size();i++) {
     printf("%d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second);
   }
  return 0;
}