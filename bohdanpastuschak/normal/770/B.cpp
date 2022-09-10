#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <stack>
#include <iostream>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mod 1000000007
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i>= (a); i)


#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cina[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6

ll poww(ll x,ll y)
{
          ll res=1;
          for(int i=0;i<y;i++)
                    res*=x;
          return res;
}

int main()
{
ll n;
cin >> n;
if (n < 10)
{
cout << n;
return 0;
}

int lastDigit = n % 10;
int numberOfDigits = 1;
int sumOfDigits = 0;
ll t = n;
while (t > 9)
{
sumOfDigits += t % 10;
t /= 10;
++numberOfDigits;
}

int firstDigit = t;
sumOfDigits += firstDigit;

int sumShouldBe = max(sumOfDigits, 9 * (numberOfDigits - 1) + firstDigit - 1);

if (sumShouldBe == sumOfDigits)
{
cout << n;
return 0;
}

vector<ll> probablyAnswers;

//add (first-1)99999
ll all9 = firstDigit - 1;

FOR(i, 0, numberOfDigits - 1)
{
          all9 *= 10;
          all9 += 9;
}
probablyAnswers.push_back(all9);

FOR(position8, 1, numberOfDigits)
{
          ll with = all9 + (ll)poww((ll)10, numberOfDigits - 1);
          with -= (ll)poww((ll)10, numberOfDigits - position8 - 1);


          if (with < n)
          probablyAnswers.push_back(with);
}

ll maxx = probablyAnswers[0];
FOR(i, 1, probablyAnswers.size())
if (maxx < probablyAnswers[i])
maxx = probablyAnswers[i];

cout << maxx<<endl;

return 0;
}