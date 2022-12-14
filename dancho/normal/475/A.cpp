#include <cstdio>
#include <cstring>

char t[1024][1024] = {
	"+------------------------+",
	"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|",
	"|#.......................|",
	"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
	"+------------------------+"
};

int main()
{
	int k;
	scanf("%d", &k);
	int ln = strlen(t[0]);
	while (k > 0)
	{
		bool fl = 0;
		for (int j = 0; j < ln && !fl; ++j)
		{
			for (int i = 0; i < 6; ++i)
			{
				if (t[i][j] == '#')
				{
					t[i][j] = 'O';
					fl = 1;
					break;
				}
			}
		}
		--k;
	}

	for (int i = 0; i < 6; ++i)
	{
		printf("%s\n", t[i]);
	}
	return 0;
}