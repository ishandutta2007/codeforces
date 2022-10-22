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
int n , temp;
vector<int> vec , sec;

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++){
	 cin >> temp;
	 vec.push_back(temp);
	 sec.push_back(temp);
    }
    sort(sec.begin() , sec.end());
    int a = 0 , b = 0;
    for (a = 0 ; a < sec.size() ; a++)
	 if (sec[a] != vec[a])   break;
    for (b = sec.size() - 1 ; b >= 0 ; b--)
	 if (sec[b] != vec[b])   break;
    if (a == sec.size())	a = sec.size() - 1;
    if (b == -1)    b = 0;
    if (a == sec.size() - 1){
	 cout << "yes" << endl;
	 cout << 1 << " " << 1 << endl;
	 return  0;
    }

    reverse(vec.begin() + a , vec.begin() + b + 1);

    int flag = 0;
    for (int i = 0 ; i < n ; i++)
	 if (sec[i] != vec[i])   flag = 1;
    if (flag == 1){
	 cout << "no" << endl;
	 return  0;
    }
    cout << "yes" << endl;
    cout << a + 1 << " " << b + 1 << endl;

    return 0;
}