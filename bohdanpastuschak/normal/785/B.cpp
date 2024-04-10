#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <iomanip>
#include <functional>
#include <list>
#include <vector>
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
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i>= (a); --i)

#define vec(a) vector<ll> a
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())
#define infinity (ll)1e18
#define epsilon 1e-6


int main()
{
	ll n, m;
	cin >> n;
	vector<pll> chess(n);
	FOR(i, 0, n)
		cin >> chess[i].first >> chess[i].second;

	cin >> m;
	vector<pll> progr(m);
	FOR(i, 0, m)
		cin >> progr[i].first >> progr[i].second;

	ll leftMostChess = 0;
	FOR(i, 1, n)
	{
		if (chess[i].second < chess[leftMostChess].second)
			leftMostChess = i;
	}

	ll rightMostChess = 0;
	FOR(i, 1, n)
	{
		if (chess[i].first > chess[rightMostChess].first)
			rightMostChess = i;
	}

	ll leftMostPr = 0;
	FOR(i, 1, m)
	{
		if (progr[i].second < progr[leftMostPr].second)
			leftMostPr = i;
	}

	ll rightMostPr = 0;
	FOR(i, 1, m)
	{
		if (progr[i].first > progr[rightMostPr].first)
			rightMostPr = i;
	}


	ll chessLeft = 0, cheessRight = 0;

	if (chess[leftMostChess].second < progr[rightMostPr].first)
		chessLeft = progr[rightMostPr].first - chess[leftMostChess].second;

	if (progr[leftMostPr].second < chess[rightMostChess].first)
		cheessRight = chess[rightMostChess].first - progr[leftMostPr].second;

	if (cheessRight > chessLeft)
		cout << cheessRight;
	else
		cout << chessLeft;
	return 0;
}