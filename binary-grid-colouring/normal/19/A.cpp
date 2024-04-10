#include<bits/stdc++.h>
using namespace std;
map<string,int>point,num_diff,num;
string s;
string name[56];
bool cmp(string s1,string s2)
{
	if(point[s1]!=point[s2])return point[s1]>point[s2];
	if(num_diff[s1]!=num_diff[s2]) return num_diff[s1]>num_diff[s2];
	return num[s1]>num[s2];
}
string s1,s2;
int n;
int num1,num2;
char c;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>name[i];
	}
	for(int i=1;i<=(n*(n-1))>>1;i++)
	{
		cin>>s>>num1>>c>>num2;
		s1 = s.substr(0,s.find("-"));
		s2 = s.substr(s.find("-")+1);
		if(num1 > num2){
			point[s1]+=3;
		}
		if(num1 < num2) 
		{
			point[s2]+=3;
		}
		if(num1==num2){
			point[s1]++;
			point[s2]++;
		}
		num[s1]+=num1;
		num[s2]+=num2;
		num_diff[s1] += num1-num2;
		num_diff[s2] += num2-num1;
	}
	sort(name+1,name+n+1,cmp);
	sort(name+1,name+(n/2+1));
	for(int i=1;i<=(n>>1);i++)
	{
		cout<<name[i]<<endl;
	}
	return 0;
}