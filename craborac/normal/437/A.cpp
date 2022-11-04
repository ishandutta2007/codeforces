#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int mas[4];
int main()
{
	string s1, s2, s3, s4;
	cin >> s1;
	cin >> s2;
	cin >> s3;
	cin >> s4;
	mas[0] = s1.size() - 2; 
	mas[1] = s2.size() - 2;
	mas[2] = s3.size() - 2;
	mas[3] = s4.size() - 2;
	int a = 0;
	int b = 0;
	for(int i = 0; i < 4; i++)
	{
		int q1 = 1;
		int q2 = 1;
		for(int j = 0; j < 4; j++)
		{
			if(i != j)
			{
				if(mas[i] < mas[j] * 2)
					q2 = 0;
				if(mas[i] * 2 > mas[j])
					q1 = 0;
			}
		}
		a += q1 * (i + 1);
		b += q2 * (i + 1);
	}
	if((a == 0) && (b == 0))
		printf("C");
	else if((a != 0) && (b != 0))
	{
		printf("C");	
	}
	else if(a != 0)
	{
		if(a == 1)
			printf("A");
		else if(a == 2)
			printf("B");
		else if(a == 3)
			printf("C");
		else
			printf("D");
	}
	else
	{
		if(b == 1)
			printf("A");
		else if(b == 2)
			printf("B");
		else if(b == 3)
			printf("C");
		else
			printf("D");
	}
	return 0;
}