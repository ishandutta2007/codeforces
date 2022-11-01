#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

#define fi first
#define se second
#define pii pair<int,int>
#define mii map<int,int>
#define ll long long
const int  md = (1e9+7);

std::map<long long , long long> mp;

//1k2500,2n5000,k  n5000)
int k,n;
long long x;

std::vector<int> ch1(26);

int main()
{
    std::cin >> k >> n;
    std::vector<int> v(k);
    std::vector<string> s(k);
    for(int i=0;i<k;i++){
      cin>>s[i];
    }
    for(auto x : s[0]){
      ch1[x-'a']++;
    }
    for(int i=1;i<k;i++){
      std::vector<int> ch2(26);
      for(auto x: s[i]){
        ch2[x-'a']++;
      }
      if (ch2!=ch1) {
        /* code */
        printf("-1\n");
        exit(0);
      }
    }
    int ok = 0;
    for(auto x:ch1){
      ok |= (x>=2);
    }
    for(int i=1;i<k;i++){
      for(int j=0;j<n;j++){
        v[i]+=(s[i][j]!=s[0][j]);
      }
    }
    // for (size_t i = 0; i < count; i++) {
    //   /* code */
    // }

  //  std::cout << "/* message */" << '\n';

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int flag = 1;
        // for (size_t i = 0; i < count; i++) {
        //   /* code */
        // }
        for(int kk=1;kk<k;kk++){
          int tmp = v[kk] -(s[kk][i]!=s[0][i]) - (s[kk][j]!=s[0][j]);
          tmp += (s[kk][j]!=s[0][i])+(s[kk][i]!=s[0][j]);
          flag &= ((tmp==0 && ok==1)||(tmp==2));
        }
        if(flag==1){
          char tmp = s[0][i];
          s[0][i] = s[0][j];
          s[0][j] = tmp;
          std::cout << s[0] << '\n';
          exit(0);
        }
      }
    }
    std::cout << -1 << '\n';
}