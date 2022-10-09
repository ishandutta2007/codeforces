for testcase in range(int(input())):
    n = int(input())
    ra, pa, sa = map(int, input().split())
    beat = {'R': 'P', 'P': 'S', 'S': 'R'}
    a_beat = {'R': pa, 'P': sa, 'S': ra}
    a_sec = []
    win_time = 0
    for i in input().strip():
        if a_beat[i] > 0:
            win_time += 1
            a_beat[i] -= 1
            a_sec.append(beat[i])
        else:
            a_sec.append('.')
    for i in range(n):
        if a_sec[i] != '.':
            continue
        for key in 'RPS':
            if a_beat[key] == 0:
                continue
            a_sec[i] = beat[key]
            a_beat[key] -= 1
            break
    print('YES\n' + ''.join(a_sec)  if win_time >= (n + 1) // 2 else 'NO')