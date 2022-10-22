#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>


using namespace std;

string str = "";
int n, a, b;
int dif;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
	cin >> a >> b;
	if(abs(dif + a) < abs(dif - b)){
	    str += "A";
	    dif += a;
	}
	else{
	    str += "G";
	    dif -= b;
	}
    }
    if(abs(dif) <= 500)cout << str << endl;
    else cout << -1 << endl;
}