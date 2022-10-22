#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;

ll t , n , k , d1 , d2;

int main(){
    cin >> t;
    for (ll i = 0 ; i < t ; i++){
	 cin >> n >> k >> d1 >> d2;
	 bool flag = 0;
	 if (n % 3 != 0){
	     cout << "no" << endl;
	     continue;
	 }
	 
	 ll temp = ll(d1 + ll(d1 + d2));// 1 >= 2 >= 3 //temp = tedaad baazi haaye laazem bara mosavi kardaneshun
	 ll tp = ll(ll((d1 + d2) * 3) - temp);//tp = hadeaghal tedaad baazi haaE ke bayad anjam shodeh baashe ta alan
	 if (k % 3 == tp % 3 && tp <= k && ll(k + temp) <= n && ll(n - ll(k + temp)) % 3 == 0)   flag = 1;
	 
	 temp = ll(d2 + ll(d1 + d2));//3 >= 2 >= 1
	 tp = ll(ll(ll(d1 + d2) * 3) - temp);
	 if (k % 3 == tp % 3 && tp <= k && ll(k + temp) <= n && ll(n - ll(k + temp)) % 3 == 0)   flag = 1;
	 
	 temp = ll(d1 + ll(d1 - d2));//1 >= 3 >= 2;
	 tp = ll(ll(d1 * 3) - temp);
	 if (d1 >= d2 && k % 3 == tp % 3 && tp <= k && ll(k + temp) <= n && ll(n - ll(k + temp)) % 3 == 0)   flag = 1;

	 temp = ll(d2 + ll(d2 - d1));//3 >= 1 >= 2
	 tp = ll(ll(d2 * 3) - temp);
	 if (d2 >= d1 && k % 3 == tp % 3 && tp <= k && ll(k + temp) <= n && ll(n - ll(k + temp)) % 3 == 0)   flag = 1;

	 temp = ll(d1 + d2);// 2 >= 1 , 3
	 if (d1 >= d2)   tp = ll(ll(d1 * 3) - temp);
	 else	  tp = ll(ll(d2 * 3) - temp);
	 if (k % 3 == tp % 3 && tp <= k && ll(k + temp) <= n && ll(n - ll(k + temp)) % 3 == 0)   flag = 1;
    
	 if (flag)   cout << "yes" << endl;
	 else	  cout << "no" << endl;
    }
    return 0;
}