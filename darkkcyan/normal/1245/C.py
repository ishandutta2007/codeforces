from sys import stdin, exit

rem = 10**9 + 7
dp = {'norm': 1, 'last_n': 0, 'last_u': 0}

for i in stdin.readline().strip():
    if i in 'mw':
        print(0)
        exit(0)

    if i not in 'nu':
        dp = {
                'norm': (dp['norm'] + dp['last_n'] + dp['last_u']) % rem,
                'last_n': 0,
                'last_u': 0
        }
        continue

    if i == 'u':
        dp = {
                'norm': (dp['last_u']) % rem,
                'last_u': (dp['last_u'] + dp['norm'] + dp['last_n']) % rem,
                'last_n': 0
        }

    if i == 'n':
        dp = {
                'norm': (dp['last_n']) % rem,
                'last_n': (dp['last_n'] + dp['norm'] + dp['last_u']) % rem,
                'last_u': 0
        }
print((dp['norm'] + dp['last_u'] + dp['last_n']) % rem)