import sys

def main():
	n = int(input())
	color = 'blue'
	lock = 'unlock'
	for _ in range(n):
		command = input()
		if command.endswith('lock'):
			lock = command
		else:
			if lock == 'unlock':
				color = command
	print(color)

if __name__ == '__main__':
	main()