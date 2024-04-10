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

struct Thing{
    int a , b , c , d , type , e;
};
int n , m , a , b , c;
vector<Thing>	  vec;

bool help(Thing a , Thing b){
    if (a.a < b.a)  return	true;
    if (a.a > b.a)  return	false;
    if (a.type != b.type)	return  a.type > b.type;
    return  a.b < b.b;
}
bool help2(Thing a , Thing b){
    if (a.b < b.b)    return true;
    if (a.b > b.b)    return false;
    if (a.a != b.a)	   return  a.a > b.a;
    return  a.e > b.e;//harki zoodtar biad bozorg tare
}

bool(*pnt)(Thing , Thing) = help2;
set<Thing , bool(*)(Thing , Thing)> st(pnt);
const int max_n = 2 * 1e5;
int ans[max_n];
Thing temp;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> a >> b;
	 temp.a = a;	   temp.b = b;     temp.type = 0;	temp.d = i + 1;
	 vec.push_back(temp);
    }
    cin >> m;
    for (int i = 0 ; i < m ; i++){
	 cin >> a >> b >> c;
	 temp.a = a;	   temp.b = b;     temp.type = 1;	temp.d = i + 1;     temp.c = c;
	 vec.push_back(temp);
    }
    sort(vec.begin() , vec.end() , help);

    for (int i = 0 ; i < vec.size() ; i++){
	 vec[i].e = i + 1;
	 if (vec[i].type == 1){
	     st.insert(vec[i]);
	     continue;
	 }
	 
	 if (st.find(vec[i]) != st.end())	  temp = *st.find(vec[i]);
	 else	  if (st.upper_bound(vec[i]) != st.end())	temp = *st.upper_bound(vec[i]);
	 else{
	     cout << "NO" << endl;
	     return 0;
	 }

	 st.erase(temp);
	 ans[vec[i].d] = temp.d;
	 temp.c -= 1;
	 if (temp.c != 0)	st.insert(temp);
    }
    cout << "YES" << endl;
    for (int i = 1 ; i <= n ; i++){
	 if (i == n) cout << ans[i] << endl;
	 else	  cout << ans[i] << " ";
    }
    return 0;
}