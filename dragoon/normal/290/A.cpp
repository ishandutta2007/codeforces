#include<stdio.h>

char name[100][100]=
{
	"",
	"Washington",
	"Adams",
	"Jefferson",
	"Madison",
	"Monroe",
	"Adams",
	"Jackson",
	"Van Buren",
	"Harrison",
	"Tyler",
	"Polk",
	"Taylor",
	"Fillmore",
	"Pierce",
	"Buchanan",
	"Lincoln",
	"Johnson",
	"Grant",
	"Hayes",
	"Garfield",
	"Arthur",
	"Cleveland",
	"Harrison",
	"Cleveland",
	"McKinley",
	"Roosevelt",
	"Taft",
	"Wilson",
	"Harding",
	"Coolidge",
	"Hoover",
	"Roosevelt",
	"Truman",
	"Eisenhower",
	"Kennedy",
	"Johnson",
	"Nixon",
	"Ford",
	"Carter",
	"Reagan"
};

int main()
{
	int a;

	scanf("%d", &a);
	printf("%s\n", name[a]);

	return 0;
}