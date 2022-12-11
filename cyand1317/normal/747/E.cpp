#include <cstdio>
#include <cstdlib>
#include <vector>
static const int MAXLEN = 1e6 + 12;

int len = 0;
char s[MAXLEN];
char *tokens[MAXLEN]; int token_ct = 0;
int max_depth = 0;
std::vector<char *> nested[MAXLEN];

int parse_comment_recursive(int start_token, int level)
{
    if (max_depth < level) max_depth = level;
    nested[level].push_back(tokens[start_token++]);
    int children = strtol(tokens[start_token++], NULL, 10);
    while (children--) {
        start_token = parse_comment_recursive(start_token, level + 1);
    }
    return start_token;
}

int main()
{
    while ((s[len] = getchar()) != '\n' && s[len] != EOF) ++len; s[len] = '\0';

    tokens[token_ct++] = s;
    for (int i = 0; i < len; ++i) if (s[i] == ',') { tokens[token_ct++] = s + i + 1; s[i] = '\0'; }

    int parsed_tokens = 0;
    while (parsed_tokens < token_ct)
        parsed_tokens = parse_comment_recursive(parsed_tokens, 0);

    printf("%d\n", max_depth + 1);
    for (int i = 0; i <= max_depth; ++i) {
        for (std::vector<char *>::iterator j = nested[i].begin(); j != nested[i].end(); ++j) {
            fputs(*j, stdout);
            putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}