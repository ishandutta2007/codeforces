import sys

try:
    while True:
        s = input()
        if s.strip() == '':
            break
        print('NO')
        sys.stdout.flush()

except:
    pass