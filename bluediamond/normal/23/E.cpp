#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <class T>
vector<T> operator + (const vector<T> &a,const vector<T> &b){
  vector<T> ans=a;
  for (int i=0;i<b.size();i++) ans.push_back(b[i]);
  return(ans);
}


class big{
public:
  vector<int> num;
  bool neg;

  inline void relax(){
    for (int i=0;i+1<(int)num.size();i++){
      num[i+1]+=num[i]/10;
      num[i]%=10;
    }

    if (num.size())
      while (num.back() >= 10){
	num.push_back(num.back()/10);
	num[num.size()-2]%=10;
      }

    while (num.size() > 1 && num.back() == 0) num.pop_back();
    if (num.size() == 1 && num[0] == 0) neg=false;
  }

  bool operator < (big s)const{
    if (neg != s.neg) return(neg);
    if (num.size() != s.num.size())
      return((num.size() < s.num.size())^neg);
    for (int i=num.size()-1;i>=0;i--)
      if (num[i] != s.num[i])
	return((num[i] < s.num[i])^neg);
    return(false);
  }

  big negative()const{
    big ans=*this;
    ans.neg=!ans.neg;
    ans.relax();
    return(ans);
  }

  big(int s=0){
    num.clear();
    neg=s < 0;
    num.push_back(abs(s));
    relax();
  }

  big operator + (big s)const{
    if (s.neg) return(operator - (s.negative()));
    if (neg) return(s - negative());
    big ans=*this;
    if (ans.num.size() < s.num.size()) ans.num.resize(s.num.size());
    for (int i=0;i<(int)s.num.size();i++)
      ans.num[i]+=s.num[i];
    ans.relax();
    return(ans);
  }

  big operator - (big s)const{
    if (s.neg) return(operator + (s.negative()));
    if (neg) return((s+negative()).negative());
    if (operator < (s))
      return((s-(*this)).negative());
    big ans=*this;
    for (int i=0;i<(int)ans.num.size();i++){
      if (i < s.num.size())
	ans.num[i] -= s.num[i];
      if (ans.num[i] < 0){
	ans.num[i+1]--;
	ans.num[i]+=10;
      }
    }
    ans.relax();
    return(ans);
  }

  big operator * (big s)const{
    if (neg) return((negative()*s).negative());
    if (s.neg) return((operator * (s.negative())).negative());
    big ans;
    ans.num.resize(s.num.size()+num.size()-1);
    for (int i=0;i<(int)num.size();i++)
      for (int j=0;j<(int)s.num.size();j++)
	ans.num[i+j]+=num[i]*s.num[j];
    ans.relax();
    return(ans);
  }

  big operator / (big s)const{
    if (s.num.size() == 1 && s.num[0] == 0)
      throw ("big : division by zero!!");

    if (neg) return((negative()/s).negative());
    if (s.neg) return((operator / (s.negative())).negative());
    big ans;
    ans.num.resize(max((int)num.size()-(int)s.num.size()+2,1));
    big sum;
    for (int i=(int)ans.num.size()-1;i>=0;i--){

      big x;
      x.num.resize(s.num.size()+i);
      for (int j=0;j<(int)s.num.size();j++)
	x.num[j+i]=s.num[j];
      x.relax();

      while (true){
	sum=sum+x;
	if (operator < (sum)){
	  sum=sum-x;
	  break;
	}
	ans.num[i]++;
      }
    }
    ans.relax();
    return(ans);
  }

  big operator % (big s)const{
    if (neg) return((negative()%s).negative());
    if (s.neg) return(operator % (s.negative()));
    return(operator - (s
* (operator / (s))));
  }
};

long long intValue(big s){
  long long ans=0;
  for (int i=(int)s.num.size()-1;i>=0;i--) ans=ans*10+s.num[i];
  if (s.neg) return(ans*-1);
  else return(ans);
}

ostream & operator << (ostream & tout,big s){
  if (s.neg) tout<<'-';
  for (int i=(int)s.num.size()-1;i>=0;i--)
    tout<<s.num[i];
  return(tout);
}

big gcd(big a,big b){
  if (a.neg) return(gcd(a.negative(),b));
  if (b.neg) return(gcd(a,b.negative()));
  if (a < b) swap(a,b);
  if (b.num.size() == 1 && b.num[0] == 0) return(a);
  return(gcd(b,a%b));
}

template<class t>
ostream & operator << (ostream & tout,const vector<t> &s){
  tout<<'[';
  for (int i=0;i<s.size();i++)
    if (i+1 == s.size())
      tout<<s[i];
    else
      tout<<s[i]<<',';
  tout<<']';
  return(tout);
}

const int N = 700 + 7;
int n;
vector<int> g[N];
big dp[N];
big prod[N];

void build(int a, int p)
{
    vector<int> kids;
    for (auto &b : g[a])
    {
        if (b != p)
        {
            kids.push_back(b);
            build(b, a);
        }
    }
    g[a] = kids;
}

struct fraction
{
    big a;
    big b;
    /// a/b
};

bool cmp(fraction f, fraction s)
{
    return s.a * f.b - f.a * s.b < 0;
}

vector<big> gigel[N];

void dfs(int a)
{
    prod[a] = 1;
    for (auto &b : g[a])
    {
        dfs(b);
        prod[a] = prod[a] * dp[b];
    }
    dp[a] = prod[a];
    vector<fraction> rap;
    for (auto &b : g[a])
    {
        rap.push_back({prod[b], dp[b]});
    }
    sort(rap.begin(), rap.end(), cmp);
    big cur = prod[a];
    for (int k = 0; k < (int) rap.size(); k++)
    {
        cur = cur * rap[k].a / rap[k].b;
        gigel[a].push_back(cur);
        dp[a] = max(dp[a], cur * (k + 2));
    }
    for (auto &b : g[a])
    {
        for (int k = 0; k < (int) gigel[b].size(); k++)
        {
            dp[a] = max(dp[a], prod[a] / dp[b] * gigel[b][k] * (k + 3));
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    build(1, -1);
    dfs(1);
    cout << dp[1] << "\n";
}