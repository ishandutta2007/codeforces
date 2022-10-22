#include <bits/stdc++.h>
using namespace std;
bool possible[100001];
string add (string a, string b) {
  string ret = ""; int carry = 0,aind,bind;
  for (aind = a.length()-1, bind = b.length()-1; aind >= 0 && bind >= 0; aind--, bind--) {
    int sum = (a[aind]-'0')+(b[bind]-'0')+carry;
    carry = sum/10;
    ret = to_string(sum%10) + ret;
  }
  for (; aind >= 0; aind--) {
    int sum = (a[aind]-'0')+carry;
    carry = sum/10;
    ret = to_string(sum%10) + ret;
  }
  for (; bind >= 0; bind--) {
    int sum = (b[bind]-'0')+carry;
    carry = sum/10;
    ret = to_string(sum%10)+ret;
  }
  if (carry) ret = to_string(carry) + ret;
  return ret;
}
string mini (string a, string b) {
  if (a=="") return b;
  if (b=="") return a;
  if (a.length() != b.length()) return a.length() > b.length() ? b : a;
  for (int x = 0; x < a.length(); x++) {
    if (a[x] < b[x]) return a;
    if (b[x] < a[x]) return b;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,start=-1,start2=-1; string s, temp1="", temp2="",ans1="",ans2="",ans3="",ans4="";
    cin >> n >> s;
    int mid = (n>>1)-1;
    for (int x = mid+1; x < n-1; x++) if (s[x+1] != '0') {start = x; break;}
    for (int x = mid; x >= 0; x--) if (s[x+1] != '0') {start2 = x; break;}
    if (start >= 0) {
      for (int x = 0; x <= start; x++) temp1 += s[x];
      for (int x = start+1; x < n; x++) temp2 += s[x];
      ans1 = add(temp1,temp2);
      if (start+1 < n-1 && s[start+2] != '0') {
        temp1 = "", temp2="";
        for (int x = 0; x <= start+1; x++) temp1 += s[x];
        for (int x = start+2; x < n; x++) temp2 += s[x];
        ans3 = add(temp1,temp2);
      }
    }
    if (start2 >= 0) {
     temp1 = ""; temp2 = "";
     for (int x = 0; x <= start2; x++) temp1 += s[x];
     for (int x = start2+1; x < n; x++) temp2 += s[x];
     ans2 = add(temp1,temp2);
     if (start2-1>=0&&s[start2]!='0') {
       temp1 = "" ,temp2= "";
       for (int x = 0; x < start2; x++) temp1 += s[x];
       for (int x = start2; x < n; x++) temp2 += s[x];
       ans4 = add(temp1,temp2);
     }
   }
     cout << mini(ans1,mini(ans2,mini(ans3,ans4))) << '\n';
    return 0;
}