#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int num1[108000], num2[108000];
string str1, str2;

int main(){
	cin >> str1 >> str2;
	int p = 0;
	for(int i = str1.size() - 1;i >= 0;i--){
		num1[p++] = (str1[i] - '0');
	}
	
	for(int i = 107999;i >= 1;i--){
		if(num1[i] == 0)continue;
		if(num1[i - 1] == 1){
			num1[i - 1] = num1[i] = 0;
			int tmp = i + 1;
			while(num1[tmp + 1] == 1){
				num1[tmp + 1] = 0;
				tmp += 2;
			}
			num1[tmp] = 1;
		}
	}
	p = 0;
	for(int i = str2.size() - 1;i >= 0;i--){
		num2[p++] = (str2[i] - '0');
	}

	for(int i = 107999;i >= 1;i--){
		if(num2[i] == 0)continue;
		if(num2[i - 1] == 1){
			num2[i - 1] = num2[i] = 0;
			int tmp = i + 1;
			while(num2[tmp + 1] == 1){
				num2[tmp + 1] = 0;
				tmp += 2;
			}
			num2[tmp] = 1;
		}
	}
	
	for(int i = 107999;i >= 0;i--){
		if(num1[i] > num2[i]){
			cout << ">" << endl;
			return 0;
		}
		if(num1[i] < num2[i]){
			cout << "<" << endl;
			return 0;
		}
	}
	cout << "=" << endl;
	return 0;
	
	
}