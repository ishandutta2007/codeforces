#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 123;
const int mod = 1e9+7;

int a[34],tmp[34],NO[34];
char op[2];
char s[123456];

int main(int argc, char const *argv[]) {
  /* code */
  int n;
  std::cin >> n;
  int ans = 0;
  int cnt = 0;
  int ok = 0;
  for (size_t i = 1; i <= n; i++) {
    scanf("%s%s",op, s);
    if(op[0]=='!'){
      cnt++;
      int len = strlen(s);
      memset(a,0,sizeof(a));
      for (size_t j = 0; j < len; j++) {
        /* code */
        a[s[j] - 'a']  = 1;
      }
      for (size_t j = 0;  j < 26; j++) {
        if(a[j] >= 1){
          tmp[j]++;
        }
      }
      for(int j = 0;j<26;j++) {
        if(tmp[j]!=cnt){
          NO[j] = 1;
        }
      }
      if(ok) {
        ans++;
      }
    }
    else if(op[0]=='.') {
    //  std::cout << "/* message */" << '\n';
      int len = strlen(s);
      memset(a,0,sizeof(a));
      for (size_t j = 0; j < len; j++) {
        a[s[j] - 'a']  = 1;
      }

      for(int j = 0;j < 26;j++) {
        if(a[j]>=1){
          NO[j] = 1;
        }
      }
    }
    else
    {
      if(ok >= 1 && n != i){
        ans++;
      }
      NO[s[0]-'a'] = 1;
    }
    if (ok==0){
			int res = 0;
			for(int j = 0; j < 26; j++) {
        if (NO[j] == 1)
        {
          res++;
        }
      }
    //  std::cout << "res= " << res << '\n';
			if (res == 25)
      {
        ok = 1;
      }
		}
  }
  std::cout << ans << '\n';
  return 0;
}