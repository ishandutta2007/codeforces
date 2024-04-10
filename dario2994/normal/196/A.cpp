#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#define INF 2000000000
#define MAXN 100010
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

char stringa[MAXN];

int main(){
	cin >> stringa;
	char last=0;
	vector <char> ris;
	for(int i=strlen(stringa)-1;i>=0;i--){
		if(stringa[i]>=last){
			ris.push_back(stringa[i]);
			last=stringa[i];
		}
	}
	for(int i=ris.size()-1;i>=0;i--)cout << ris[i];
}