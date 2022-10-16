//  228

#include <bits/stdc++.h>
#define integer int
#define int long long
#define fi first
#define modulo 1000003
#define sc second
#define pii pair<int, int>
#define vi vector<int>
#define mii map<int, int>
#define msi map<string, int>
#define si set<int>
#define all(v) v.begin(), v.end()
#define sz(v) int((v).size())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dep(i, a, b) for (int i = a; i >= b; i--)
#define isinarr(i, n) ((i >= 0) ? ((i < n) ? 1 : 0) : 0)
#define fastio                         \
     ios_base::sync_with_stdio(false); \
     cin.tie(NULL);                    \
     cout.tie(NULL);
#define pb push_back
#define ppb pop_back
#define lb lower_bound
#define ub upper_bound
#define present(container, element) (container.find(element) != container.end())        //set,map etc.
#define cpresent(container, element) (find(all(container), element) != container.end()) //vector
#define hell 1000000007
#define PI 3.14159265
#define mp make_pair
#define inparr(a, n) rep(i, 0, n) cin >> a[i];
#define strwspaces(s) getline(cin, s)
#define give(x, y) cout << x << " " << y << endl;
#define setp(n) cout << fixed << setprecision(n);
#define endl '\n'
#define inp(n) \
     int n;    \
     cin >> n;
#define inps(s) \
     string s;  \
     cin >> s;
#define setmem(inde, k) memset(inde, k, sizeof(inde))
#define tr(a, m) for (auto a = m.begin(); a != m / end(); a++)
using namespace std;

void solve()
{

     inp(n);
     vector<int> a(n);
     inparr(a, n);
     //  rep(i,0,n)
     //  cout<<a[i]<<endl;
     vector<vector<int>> vec(1000000);
     vector<pair<int, int>> ans;
     rep(i, 0, n)
         vec[a[i]]
             .pb(i);

     for (int i = 0; i < vec.size(); i++)
     {
          if (vec[i].size() == 0)
               continue;
          else if (vec[i].size() == 1)
               ans.push_back(make_pair(i, 0));
          else if (vec[i].size() == 2)
          {
               ans.push_back(make_pair(i, vec[i][1] - vec[i][0]));
          }
          else
          {
               bool ch = 0;
               int dif = vec[i][1] - vec[i][0];
               for (int j = 0; j < vec[i].size() - 1; j++)
               {
                    if (vec[i][j + 1] - vec[i][j] != dif)
                    {
                         ch = 1;
                         break;
                    }
               }
               if (ch == 0)
               {
                    ans.push_back(make_pair(i, dif));
               }
          }
     }
     cout << ans.size() << endl;
     rep(i, 0, ans.size())
             cout
         << ans[i].first << " " << ans[i].second << endl;
}
unsigned int power(unsigned int a, unsigned int b)
{
     unsigned int res = 1;
     while (b != 0)
     {
          res = (res * a) % modulo;
     }
     return res;
}

void solve2()
{

     string s;
     cin >> s;
     unsigned int sum = 0;
     for (int i = 0; i < s.size(); i++)
     {
          int z = 0;
          if (s[i] == '>')
          {
               z = 8;
          }
          else if (s[i] == '<')
          {
               z = 9;
          }
          else if (s[i] == '+')
          {
               z = 10;
          }
          else if (s[i] == '-')
          {
               z = 11;
          }
          else if (s[i] == '.')
          {
               z = 12;
          }
          else if (s[i] == ',')
          {
               z = 13;
          }
          else if (s[i] == '[')
          {
               z = 14;
          }
          else if (s[i] == ']')
          {
               z = 15;
          }
          int n = s.length();
          for (unsigned int k = 0; k < 4 && z != 0; k++)
          {

               unsigned int p = pow(2, 4 * (n - (i + 1)) + k);
               p = p % modulo;
               if (z & 1 == 1)
                    sum = (sum % modulo + p % modulo);
               //cout<<sum<<endl;
               z = z >> 1;
          }
          //cout<<sum<<endl;

          //         ">"  1000,
          // "<"  1001,
          // "+"  1010,
          // "-"  1011,
          // "."  1100,
          // ","  1101,
          // "["  1110,
          // "]"  1111.
     }
     cout << sum << endl;
}

void solve3()
{
     int n, m, d;
     cin >> n >> m >> d;
     vector<int> vec(n * m);
     for (int i = 0; i < n * m; i++)
     {
          cin >> vec[i];
     }

     sort(vec.begin(), vec.end());
     int siz = vec.size();
     int media;
     if (siz % 2 != 0)
          media = vec[siz / 2];
     else
     {
          media = (vec[(siz / 2) - 1]);
     }
     int count = 0;

     for (int i = 0; i < siz; i++)
     {

          if (((media - vec[i]) % d) != 0)
          {
               count = -1;
               break;
          }
          else
          {
               count += (abs(media - vec[i]) / d);
          }
     }
     cout << count << endl;
}

void solve4()
{

     int n, k;
     cin >> n >> k;
     //cin>>n>>k;
     vector<int> v(2 * n + 1);
     int mini = INT_MAX, ind = INT_MAX;
     rep(i, 0, n)
     {
          cin >> v[i];
          if (mini > v[i])
          {
               ind = i;
               mini = v[i];
          }
          mini = min(mini, v[i]);
     }
     if (n == k)
     {
          cout << ind+1 << endl;
          return;
     }

     rep(i, n, 2 * n)
         v[i] = v[i - n];
     int prev = INT_MAX, sum = 0, index = 0;
     vector<bool>check(k+1);
     for (int i = 0; i < n / 2; i++)
     {
          if(check[i%k]!=1){
               check[i%k]=1;
          sum = v[i];
          for (int j = i + k; j < n + i;)
          { 
               sum += v[j];
               j += k;
          }
          if (sum < prev)
          {
               //cout<<sum<<endl;
               index = i;
               prev = sum;
          }
     }
   }
     cout << index + 1 << endl;
}
  
  void prime(vector<bool>&arr,int n){
            
            arr[0]=0;
            arr[1]=0;

            for(int i=0;i<sqrt(n);i++){
                  if(arr[i]==1){
                       for(int j=2*i;j<=n;j+=i){
                          arr[i]=1;
                       }
                  }
            }
}



void solve5(){
    int n;
    cin>>n;
    //vector<bool>arr(n,1);
    //prime(arr,n+1);   
    cout<<n<<endl;
    for(int i=n/2;i>=1;i--){
         if(n%i==0){
            cout<<i<<endl;
            n=i;
         }
    }     
}

void solve6(){
      
      string s1,s2;
      cin>>s1>>s2;
     vector<int>v1(27);
     vector<int>v2(27);
     for(int i=0;i<s1.length();i++){
          v1[s1[i]-'a']++;
     }
     for(int i=0;i<s2.length();i++){
          v2[s2[i]-'a']++;
     }
     int count=0;
     for(int i=0;i<27;i++){
           
           if(v1[i]!=0 && v2[i]!=0){
           if(v1[i]==v2[i]){
             count+=v1[i];
           }
           else if(v1[i]<v2[i]){
             count+=v1[i];
           }
           else if(v1[i]>v2[i]){
                count+=v2[i];
           }

          }
          if(v2[i]!=0 && v1[i]==0){
               count=-1;
               break;
          }
     }
     if(count==0)
      cout<<count-1<<endl;
      else
   cout<<count<<endl;




}

void sol(){

   int n,x0,y0;
   cin>>n>>x0>>y0;
      set<double>s; 
   //   int count=0; 
       int infslope=0;
   while(n--){
        double a,b;
        cin>>a>>b;
          double slope;
         
         if(a!=x0)
        {  slope=(b-y0)/(a-x0);
           s.insert(slope);
         //  cout<<slope<<endl; 
         }
         else{
         infslope=1;   
         }
   }
    cout<<s.size()+infslope<<endl;


}
void sol2(){
     int n;
     cin>>n;
     vector<int >vec(n);
     rep(i,0,n)
     cin>>vec[i];
      int maxi=INT_MIN;  
     int prev=INT_MIN;
    for(int i=0;i<n;i++){
        int lmin=vec[i];
        int j=i;
        int count=0;
        while(j>=0){
            
             if(vec[j]<=lmin){
                  lmin=vec[j];
                  count++;
             }
             else{
                  break;
             }
           j--;
        }
        int rmin=vec[i];
        int k=i;
        while(k<n){
            
             if(vec[k]<=rmin){
                  rmin=vec[k];
                  count++;
             }
             else{
                  break;
             }
           k++;
        }
        //cout<<count<<endl;
         maxi=max(count,prev);
         prev=maxi;
    }

   cout<<maxi-1<<endl;
}


signed main()
{

     //cout<<"helo"<<endl;

     int t = 1;
     // cin>>t;
     while (t--)
     {
          //solve();
          sol2();
     }

     return 0;
}